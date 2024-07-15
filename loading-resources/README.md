# Scenario 1

I want my program to have access to a single txt file from a designated resource directory.

```
.
├── BUILD
├── resources
│   ├── BUILD
│   └── r1.txt
├── src
│   ├── BUILD
│   └── main.cpp
└── WORKSPACE
```

```
# resources/BUILD

exports_files(["r1.txt"])
```

```
# src/BUILD

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    data = ["//resources:r1.txt"],
)
```

```
bazel run //src:main
```

```
INFO: Running command line: bazel-bin/src/main.exe
Current working directory: ~\_bazel~1\xrxzu7js\execroot\_main\bazel-~1\x64_wi~1\bin\src\mainex~2.run\_main

Directory tree:
|-- resources
|   `-- r1.txt
`-- src
    `-- main.exe

Attempting to open file: resources/r1.txt
File contents:
Hello from r1.txt!
This is a sample content.
```

# Scenario 2

I want my program to have access to multiple files that are located in a designated resource directory recursively.

```
.
├── BUILD
├── resources
│   ├── BUILD
│   ├── r1.txt
│   ├── r2.txt
│   ├── r3.png
│   └── subfolder1
│       └── r4.txt
├── src
│   ├── BUILD
│   └── main.cpp
└── WORKSPACE
```

```
# resources/BUILD

filegroup(
    name = "resources",
    srcs = glob(["**"]),
    visibility = ["//visibility:public"],
)
```

```
# src/BUILD

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    data = ["//resources:resources"],
)
```

```
bazel run //src:main
```

```
INFO: Running command line: bazel-bin/src/main.exe
Current working directory: ~\_bazel~1\7pyc5vre\execroot\_main\bazel-~1\x64_wi~1\bin\src\mainex~2.run\_main

Directory tree:
|-- resources
|   |-- BUILD
|   |-- r1.txt
|   |-- r2.txt
|   |-- r3.png
|   `-- subfolder1
|       `-- r4.txt
`-- src
    `-- main.exe

Attempting to open file: resources/subfolder1/r4.txt
File contents:
Hello from r4.txt!
This is a sample content.
```

# Scenario 3

- I want my program to have access to multiple files that are located in a designated resource directory recursively.

- And I want to avoid placing the resource manifest in the folder, I want something like a root level control.

```diff
.
+ ├── BUILD
  ├── resources
- │   ├── BUILD
  │   ├── r1.txt
  │   ├── r2.txt
  │   ├── r3.png
  │   └── subfolder1
  │       └── r4.txt
  ├── src
  │   ├── BUILD
  │   └── main.cpp
  └── WORKSPACE
```

```
# BUILD

filegroup(
    name = "all_resources",
    srcs = glob(["resources/**"]),
    visibility = ["//visibility:public"],
)
```

```diff
# src/BUILD

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
-   data = ["//resources:resources"],
+   data = ["//:all_resources"],
)
```

```
bazel run //src:main
```

```
INFO: Running command line: bazel-bin/src/main.exe
Current working directory: ~\_bazel~1\7pyc5vre\execroot\_main\bazel-~1\x64_wi~1\bin\src\mainex~2.run\_main

Directory tree:
|-- resources
|   |-- BUILD
|   |-- r1.txt
|   |-- r2.txt
|   |-- r3.png
|   `-- subfolder1
|       `-- r4.txt
`-- src
    `-- main.exe

Attempting to open file: resources/subfolder1/r4.txt
File contents:
Hello from r4.txt!
This is a sample content.
```

# Note for windows

```
bazel run //src:main --enable_runfiles
```

> or `bazel run src:main --enable_runfiles`

- Creating symlinks on Windows requires one of the following:
    1. Bazel is run with administrator privileges.
    2. The system version is Windows 10 Creators Update (1703) or later and developer mode is enabled.

# Comparison of filegroup vs exports_files:

1. Purpose:
   filegroup:
   - Bundles multiple files into a single logical group
   - Allows other rules to reference this group as a single unit
   - Mainly used as input for build rules

   exports_files:
   - Allows direct reference to individual files from other packages
   - Primarily used to expose single files externally

2. File Reference Method:
   filegroup:
   - Referenced by group name (e.g., "//path/to/package:resources")
   - Individual files within the group can be accessed by file name

   exports_files:
   - Individual files are directly referenced (e.g., "//path/to/package:file.txt")

3. Visibility Control:
   filegroup:
   - Can control visibility for the entire group using the visibility attribute
   - Cannot set different visibility for individual files within the group

   exports_files:
   - Visible to all packages by default
   - Can control visibility for individual files using the visibility attribute

4. Metadata and Additional Attributes:
   filegroup:
   - Can define additional metadata for the file group (e.g., tags)
   - Can include license information for the group

   exports_files:
   - Does not include additional metadata by default
   - Can specify license information for individual files if needed

5. Performance and Build Graph:
   filegroup:
   - Can simplify the build graph by grouping many files
   - Can improve build performance in large projects

   exports_files:
   - Each file is individually included in the build graph
   - Exporting many files individually can complicate the build graph

6. Flexibility:
   filegroup:
   - Can dynamically define file sets (e.g., using glob)
   - Can include other filegroups, allowing for hierarchical structures

   exports_files:
   - Typically used for static file lists
   - Allows for more granular control over individual files

Comparing the given examples:

1. `filegroup(name = "resources", srcs = glob(["**"]), visibility = ["//visibility:public"])`
   - This method groups all files in the current directory as a group named "resources".
   - Uses `glob(["**"])` to include all files and subdirectories.
   - The group is publicly accessible (`visibility = ["//visibility:public"]`).
   - Other packages can reference the entire group as `//path/to/package:resources`.

2. `exports_files([glob("**")])`
   - This method exports all files in the current directory individually.
   - Each file can be directly referenced from other packages.
   - By default, all exported files are publicly accessible.

Key differences:
- filegroup treats files as a single unit, while exports_files handles each file individually.
- filegroup allows controlling visibility for the entire group at once, whereas with exports_files, you might need to control visibility for each file individually if needed.
- filegroup can include additional metadata for the group, but exports_files doesn't by default.

Choose the appropriate method based on your use case. If you frequently use multiple files as a unit, filegroup might be more suitable. If you need fine-grained control over individual files, exports_files might be more appropriate.