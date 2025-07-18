FROM ubuntu:22.04

# 1. Install build tools & OpenCV
RUN apt-get update && apt-get install -y \
    cmake \
    build-essential \
    libopencv-dev \
    && rm -rf /var/lib/apt/lists/*

# 2. Copy project into container
WORKDIR /app
COPY . .

# 3. Build it
RUN cmake . && make

# 4. Default: run the segmentation
CMD ["./lung_ct"]
