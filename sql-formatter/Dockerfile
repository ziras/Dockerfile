FROM php
MAINTAINER foliolin <foliolin@users.noreply.github.com>

COPY ./format /tmp/format

WORKDIR /foliolin

RUN docker-php-ext-install mbstring && \
    curl --location https://github.com/phpmyadmin/phpmyadmin/archive/66f8e7d1db59ae87c7253b348ac9933d20def56a.tar.gz | tar xz && \
    mv phpmyadmin-66f8e7d1db59ae87c7253b348ac9933d20def56a sql-formatter && \
    mv /tmp/format /foliolin/sql-formatter/format && \
    ln -s /foliolin/sql-formatter/format /usr/local/bin

ENTRYPOINT ["format"]
