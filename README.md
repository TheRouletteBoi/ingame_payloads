# ingame_payloads
load and inject payloads into memory to execute your mod menu.

 
# Building
ps3dev folder requires PSDK3v2 

sony folder requires Official Sony PS3 4.75+ SDK


# Loading
if you want to load your payload into a game you must use ps3mapi syscalls like ps3mapi_process_page_allocate and ps3mapi_create_process_thread in COBRA or MAMBA.

# Why use a payload instead of sprx?

PROS
- use up to date gcc toolchain compiler for latest C++ syntax
- low memory footprint which means you can add way more features than a sprx could 

CONS
- you can't use built-in PS3 functions like cellMsgDialogOpen2 due to no availability of exports
