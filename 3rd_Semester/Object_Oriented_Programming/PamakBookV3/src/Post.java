import java.io.Serializable;
import java.util.Comparator;
import java.util.Date;

public class Post implements Serializable {

    private final Date timestamp;
    private String content;
    private final User author;

    public Post(User author, String content) {
        this.timestamp = new Date();
        this.author = author;
        this.content = content;

    }

    public Date getTimestamp() {
        return timestamp;
    }

    public String getContent() {
        return content;
    }

    public User getAuthor() {
        return author;
    }

    @Override
    public String toString() {
        return "Post{" + "timestamp=" + timestamp + ", content='" + content + '\'' + '}';
    }
}

class PostComparator implements Comparator<Post> {

    public int compare(Post post1, Post post2) {
        Date timestamp1 = post1.getTimestamp();
        Date timestamp2 = post2.getTimestamp();
        return timestamp2.compareTo(timestamp1);
    }

}
