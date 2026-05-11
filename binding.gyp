{
  "targets": [
    {
      "target_name": "tsinterop",
      "sources": [
        "c++/tsinterop.cpp",
        "c++/process.cpp",
        "c++/mic.cpp"
      ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")",
        "./c++",
        "./c++/include",
        "./node_modules/node-addon-api"
      ],
      "library_dirs": [
        "./c++/lib"
      ],
      "libraries": [
        "moonshine.lib",
        "onnxruntime.lib",
        "bin-tokenizer.lib",
        "moonshine-utils.lib",
        "ort-utils.lib",
        "ws2_32.lib",
        "legacy_stdio_definitions.lib"
      ],
      "msvs_settings": {
        "VCCLCompilerTool": {
          "ExceptionHandling": 1,
          "RunTimeLibrary": 2,
          "AdditionalIncludeDirectories": [
            "$(ProjectDir)\\node_modules\\node-addon-api",
            "$(ProjectDir)\\c++"
          ]
        },
        "VCLinkerTool": {
          "AdditionalLibraryDirectories": [
            "$(ProjectDir)\\c++\\lib"
          ],
          "AdditionalDependencies": [
            "moonshine.lib",
            "onnxruntime.lib",
            "bin-tokenizer.lib",
            "moonshine-utils.lib",
            "ort-utils.lib",
            "ws2_32.lib",
            "legacy_stdio_definitions.lib"
          ]
        }
      }
    }
  ]
}