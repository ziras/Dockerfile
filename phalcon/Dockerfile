FROM php:5.5-apache
MAINTAINER foliolin <foliolin@users.noreply.github.com>

# Phalcon's optional dependencies
RUN apt-get update && \
    apt-get install -y \
        libmcrypt-dev \
        libpq-dev \
        libssl-dev \
        && \
    apt-get clean && \

    docker-php-ext-install \
        mbstring \
        mcrypt \
        pdo_mysql \
        pdo_pgsql \
        && \

    pecl install \
        mongo \
        && \
    echo 'extension=mongo.so' > /usr/local/etc/php/conf.d/mongo.ini && \
    pecl clear-cache

# docker-php-ext-install phalcon doesn't work
RUN apt-get install -y \
        gcc \
        libpcre3-dev \
        make \
        php5-dev \
        php5-mysql \
        git \
        && \
    apt-get clean && \

    git clone \
        --branch=phalcon-v1.3.4 \
        --depth=1 \
        https://github.com/phalcon/cphalcon.git && \
    cd cphalcon/build && ./install && cd ../.. && \
    echo 'extension=phalcon.so' > /usr/local/etc/php/conf.d/phalcon.ini && \
    rm -fr cphalcon

# We uses .htaccess
RUN a2enmod rewrite

# Composer install depends on Phalcon version
RUN docker-php-ext-install \
        pcntl \
        zip \
        && \
    curl -sS https://getcomposer.org/installer | \
    php -- --install-dir=/usr/local/bin --filename=composer

RUN composer global require --dev 'phalcon/devtools:1.3.x-dev' && \
	ln -s ~/.composer/vendor/bin/phalcon.php /usr/bin/phalcon && \
	chmod ugo+x /usr/bin/phalcon
