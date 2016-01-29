FROM php:5.5
MAINTAINER foliolin <foliolin@users.noreply.github.com>

RUN curl -sS https://getcomposer.org/installer | php -- --install-dir=/usr/local/bin --filename=composer
RUN apt-get update && apt-get install -y git
RUN apt-get update && apt-get install -y zlib1g-dev
RUN docker-php-ext-install zip

WORKDIR /foliolin/composer
