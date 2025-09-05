FROM ubuntu:24.04 AS build
RUN apt-get update && apt-get install -y build-essential cmake git
WORKDIR /app
COPY . .
RUN cmake -S . -B build -DCMAKE_BUILD_TYPE=Release \
 && cmake --build build -j \
 && cmake --install build --prefix /out

FROM debian:stable-slim
COPY --from=build /out/bin/stlfind /usr/local/bin/stlfind
ENTRYPOINT ["stlfind"]
