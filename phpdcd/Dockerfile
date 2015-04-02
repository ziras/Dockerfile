FROM php
MAINTAINER foliolin@users.noreply.github.com
RUN curl https://phar.phpunit.de/phpdcd.phar -so phpdcd.phar
RUN chmod +x phpdcd.phar
RUN mv phpdcd.phar /usr/local/bin/phpdcd
RUN mkdir -p /foliolin/phpdcd/
CMD ["phpdcd", "--recursive", "/foliolin/phpdcd/"]
