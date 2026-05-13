{
  "targets": [
    {
      "target_name": "tsinterop",
      "sources": [
        "c++/tsinterop.cpp",
        "c++/process.cpp",
        "c++/mic.cpp"
      ],
      "cflags_cc": [
          "-std=c++20"
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
        "moonshine_tts_core.lib",
        "moonshine_tts_ort.lib",
        "moonshine_tts_utf8proc.lib"
      ],
      "copies": [{
        "destination": "<(PRODUCT_DIR)",
        "files": ["c++/lib/onnxruntime.dll"]
      }],
      "msvs_settings": {
        "VCCLCompilerTool": {
          "ExceptionHandling": 1,
          "LanguageStandard": "stdcpp20",
          "RunTimeLibrary": "MultiThreadedDLL",
          "AdditionalOptions": ["/MD"],
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
            "moonshine_tts_core.lib",
            "moonshine_tts_ort.lib",
            "moonshine_tts_utf8proc.lib"
          ]
        }
      }
    }
  ]
}