import time
import pandas as pd
from sklearn.metrics.pairwise import cosine_similarity


def filter_ratings(df, limit):
    user_counts = df['userId'].value_counts()
    movie_counts = df['movieId'].value_counts()

    filtered_users = user_counts[user_counts >= limit].index
    filtered_movies = movie_counts[movie_counts >= limit].index

    filtered_df = df.loc[df['userId'].isin(filtered_users) & df['movieId'].isin(filtered_movies)]
    return filtered_df


def split_ratings(df, ratio, total):
    df_shuffled = df.sample(frac=1, random_state=0)
    wanted_len = round(total * ratio)
    wanted = df_shuffled.iloc[:wanted_len, :].sort_index()
    rest = df_shuffled.iloc[wanted_len:, :].sort_index()
    return wanted, rest


def calculate_similarity(ratings_df):
    pivot = ratings_df.pivot_table(index='userId', columns='movieId', values='rating')
    pivot.fillna(0, inplace=True)

    # Adjust ratings using mean rating
    mean_ratings = pivot.mean(axis=1)
    norm_pivot = pivot.subtract(mean_ratings, axis=0)

    # Get cosine similarity
    similarity_matrix = pd.DataFrame(cosine_similarity(norm_pivot.T))

    # Keep original ids as column and row labels
    similarity_matrix.index = pivot.columns
    similarity_matrix.columns = pivot.columns

    return similarity_matrix


def get_rated_movies_of_user(df, user_id):
    pivot = df.pivot_table(index='userId', columns='movieId', values='rating')
    user_ratings = pd.DataFrame(pivot.loc[user_id].dropna(axis=0, how='all'))
    return user_ratings


def get_common_user_count(movie1, movie2, df):
    users1 = df[df['movieId'] == movie1]['userId']
    users2 = df[df['movieId'] == movie2]['userId']
    df = pd.merge(users1, users2, how='inner', on='userId')
    return len(df)


def get_closest_movie_ratings(df, sim_df, user_id, movie_id, k):
    movie_sim_df = sim_df.loc[movie_id]
    user_rated = get_rated_movies_of_user(df, user_id)
    merged = user_rated.merge(movie_sim_df, on="movieId")
    merged.columns = ["rating", "similarity"]
    merged.sort_values(by="similarity", ascending=False, inplace=True)
    merged = merged.head(k)
    merged = merged[merged['similarity'] > 0]
    counts = [get_common_user_count(movie_id, idx, df) for idx in merged.index]
    merged['commonUsers'] = counts
    return merged


def average(df):
    return df["rating"].mean()


def weighted_average(df, by="similarity"):
    avg = 0
    for index, row in df.iterrows():
        avg += row["rating"] * row[by]
    avg = avg / df[by].sum()
    return avg


def common_user_weighted_average(df):
    return weighted_average(df, "commonUsers")


def predict_rating(df, sim_df, user_id, movie_id, k):
    closest = get_closest_movie_ratings(df, sim_df, user_id, movie_id, k)
    results = {
        "Avg": average(closest),
        "simAvg": weighted_average(closest),
        "userAvg": common_user_weighted_average(closest)
    }
    return results


def main(filter_limit, neighbours, train_ratio):
    df = pd.read_csv("ratings.csv")
    df = filter_ratings(df, filter_limit)

    print(f"Full set size: {len(df)}")
    control_df, rest_df = split_ratings(df, 0.10, len(df))
    print(f"Control-Test set size: {len(control_df)}")

    train_df, ignore_set = split_ratings(df, train_ratio, len(df))
    print(f"Train set size: {len(train_df)}")

    print("\nCalculating Similarity Matrix")
    sim_df = calculate_similarity(train_df)
    print(f"Similarity Matrix Size: {len(sim_df)}")


    print("\nProcessing Predictions:")
    k = neighbours
    i = 1
    segment = len(control_df) // 10
    predict_df = control_df.copy().drop(['userId', 'movieId', 'timestamp'], axis=1)
    predict_df['Avg'] = None
    predict_df['simAvg'] = None
    predict_df['userAvg'] = None
    predict_df['dAvg'] = None
    predict_df['dsimAvg'] = None
    predict_df['duserAvg'] = None
    start = time.perf_counter()
    elapsed = 0
    for index, row in control_df.iterrows():
        if i % segment == 0:
            elapsed += time.perf_counter() - start
            remaining = (10 * (time.perf_counter() - start)) - elapsed
            print(f'\n{i // segment}0% (elapsed: {elapsed:.2f}s, remaining {remaining:.2f}s)')
            start = time.perf_counter()
        if i % (segment // 10) == 0 and i / segment <10:
            print('.', end="")
        i += 1
        prediction = predict_rating(train_df, sim_df, row['userId'], row['movieId'], k)
        predict_df.loc[index, 'Avg'] = prediction['Avg']
        predict_df.loc[index, 'simAvg'] = prediction['simAvg']
        predict_df.loc[index, 'userAvg'] = prediction['userAvg']
        predict_df.loc[index, 'dAvg'] = abs(prediction['Avg'] - predict_df.loc[index, 'rating'])
        predict_df.loc[index, 'dsimAvg'] = abs(prediction['simAvg'] - predict_df.loc[index, 'rating'])
        predict_df.loc[index, 'duserAvg'] = abs(prediction['userAvg'] - predict_df.loc[index, 'rating'])
    print(f"Avg MAE: {predict_df['dAvg'].mean()}")
    print(f"Weighted Avg MAE: {predict_df['dsimAvg'].mean()}")
    print(f"User Weighted Avg MAE: {predict_df['duserAvg'].mean()}")


if __name__ == "__main__":
    main(5, 2, 0.70) # Filter Limit, Neighbours, Train Ratio
