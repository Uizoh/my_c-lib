import sys
import os

compiler = "gcc"
comp_flags = "-lm -o"
sanity_flags = "-Wall -pedantic -fsanitize=address -g"

source_file1 = sys.argv[1]
source_file2 = sys.argv[2]
target_file = sys.argv[3]


result = os.system(
    f"{compiler} {source_file1} {source_file2} {comp_flags} {target_file} {sanity_flags}"
)

print("\n============================")
print(f"Compiled with code: {result}", end="")
print("\n============================")

result = os.system(f"./{target_file}")

print("\n============================")
print(f"Ran with code: {result}", end="")
print("\n============================")
