FROM python:3

MAINTAINER foliolin <foliolin@users.noreply.github.com>

ENV VERSION 0.9.21

RUN git clone --branch=${VERSION} --depth=1 https://github.com/exosite/exoline.git && \
    cd exoline && \
    python setup.py install && \
    cd / && \
    rm -fr exoline

ENTRYPOINT ["exoline"]
