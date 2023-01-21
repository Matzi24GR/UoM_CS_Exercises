FROM php:8.0-apache
ENV DB_HOST='db'
ENV DB_NAME='bankDB'
ENV DB_USERNAME='root'
ENV DB_PASSWORD=''
WORKDIR /var/www/html
COPY ./php/ /var/www/html
RUN docker-php-ext-install mysqli pdo pdo_mysql && a2enmod rewrite && a2enmod headers && sed -ri -e 's/^([ \t]*)(<\/VirtualHost>)/\1\tHeader set Access-Control-Allow-Origin "*"\n\1\2/g' /etc/apache2/sites-available/*.conf
EXPOSE 80
