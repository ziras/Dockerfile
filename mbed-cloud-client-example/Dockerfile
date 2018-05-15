FROM foliolin/mbed-cloud-client-example-builder
COPY ./mbed_cloud_dev_credentials.c /mbed-cloud-client-example/mbed_cloud_dev_credentials.c
RUN python pal-platform/pal-platform.py fullbuild --target x86_x64_NativeLinux_mbedtls --toolchain GCC --external ./../define.txt --name mbedCloudClientExample.elf

FROM debian:stretch-slim
COPY --from=0 /mbed-cloud-client-example/out/Debug/mbedCloudClientExample.elf /usr/local/bin/mbedCloudClientExample.elf
ENTRYPOINT ["mbedCloudClientExample.elf"]
