FROM ubuntu:latest

ENV JAVA_HOME="/usr/lib/jvm/java-8-openjdk-amd64/"
RUN apt-get update && \
    apt-get install -y \
        build-essential \
        cmake \
        default-jdk \
        default-jre \
        libssl-dev \
        openssl \
        python \
        uuid-dev \
        wget && \
        echo 'GOOD'
RUN cd /tmp && \
    wget http://archive.apache.org/dist/qpid/proton/0.7/qpid-proton-0.7.tar.gz && \
    tar xvfz qpid-proton-0.7.tar.gz && \
    mkdir /tmp/qpid-proton-0.7/build && \
    cd /tmp/qpid-proton-0.7/build && \
    cmake -DCMAKE_INSTALL_PREFIX=/usr .. && \
    make install
COPY ./sender.c /tmp/qpid-proton-0.7/build/sender.c
RUN cd /tmp/qpid-proton-0.7/build/ && \
    gcc sender.c -o sender -lqpid-proton
WORKDIR /tmp/qpid-proton-0.7/build/
CMD ["./sender"]
