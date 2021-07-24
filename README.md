# UnityAssetBundleManifestReplacer
Unity ABM Shaping Utility.

---
## Description

Shaping a file that contains the asset bundle information for a game created in Unity.

`uabmr <INPUT-PATH> <OPTIONS> <OUTPUT-PATH>`
  
The `<OPTIONS>` argument must be one of the following.
  
`-d: Perform UABM shaping in the usual way.`  
 In most cases, this is the best option.  
  
`-s: Perform UABM shaping in your own way.`  
(by specifying regular expressions by the user).  
This is for advanced users, and is useful when formatting with the -d option does not work.  
  
The `<INPUT-PATH>` argument is the full path of the file to be shaping.
The extension must be one of the following: .data, .unity3d, .txt.  

The `<OUTPUT-PATH>` argument is the full path of the file to be output.

Example usage:

`uabmr D:\DebugDirectory\UABMR\test.data -d D:\DebugDirectory\UABMR\test_spd.txt` (Shaping UABM in the usual way)

`uabmr D:\DebugDirectory\UABMR\test.data -s D:\DebugDirectory\UABMR\test_spd.txt` (Shaping UABM in your own way)
