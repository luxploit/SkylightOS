# SkylightOS - Contribution Guildlines

## Code Headers

All Files must have the following headers:

C/C++ Files (.c, .cpp, .h, .hpp)
```c
/* [filename]
 * Created on [date] by [github username/regular name]
 * Codename "[current codename]" Operating System
 * Copyright (c) [year] - SkylightOS Project
*/
```

Assembly Files (.asm)
```x86asm
; [filename]
; Created on [date] by [github username/regular name]
; Codename "[current codename]" Operating System
; Copyright (c) [year] - SkylightOS Project
```

If you're using Visual Studio Code, it's recommended to use this extension: https://marketplace.visualstudio.com/items?itemName=doi.fileheadercomment. Pressing Ctrl+Shift+P and select "FileHeaderCommand: Select from Available Templates" to choose a C or ASM header.

```json
// Laura Raine's Extension Config
"fileHeaderComment.parameter":{
        "*":{
            "cc_commentbegin": "/*",
            "cc_commentprefix": " *",
            "cc_commentend": "*/",
            "asm_comment": ";",
            "name": "Laura Raine (lnkexploit)",
            "esaul_codename": "Esaul"
        }
    },
    "fileHeaderComment.template":{
        "esaul-asm":[
            "${asm_comment} ${filename}",
            "${asm_comment} Created on ${date} by ${name}",
            "${asm_comment} Codename \"${esaul_codename}\" Operating System",
            "${asm_comment} Copyright (c) ${year} - SkylightOS Project",
        ],
        "esaul-c":[
            "${cc_commentbegin} ${filename}",
            "${cc_commentprefix} Created on ${date} by ${name}",
            "${cc_commentprefix} Codename \"${esaul_codename}\" Operating System",
            "${cc_commentprefix} Copyright (c) ${year} - SkylightOS Project",
            "${cc_commentend}"
        ]
    }
```

## Pull Requests

All Pull Requests that relate to the OS itself must successfully build, package and install on real hardware. This is to ensure and rule out Virtual Machine flackyness and to provide accurate results. Development can however be done using QEMU or Bochs (Bochs can be used however not supported by default, a PR for it would be welcome).

## Issues and Feature Ideas

Please provide detailed information about Issues you have. Feature Ideas may be submitted but only if you intend on working on SkylightOS and implementing said feature.

## Code Style

All code written must be using snake_case (lowercase only). Kernel Mode code has to be C or C++. Assembly has to be either extensively documented or rewritten to C code before publishing. Rust, C++ and Java are used for userland code for all  