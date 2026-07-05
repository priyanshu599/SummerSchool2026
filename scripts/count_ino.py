import os

count = 0

for root, dirs, files in os.walk("."):
    for file in files:
        if file.endswith(".ino"):
            count += 1

print(f"Total Arduino (.ino) files: {count}")