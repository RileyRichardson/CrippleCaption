import path from 'path'
let cppInterop:any = null;
try{
    cppInterop = require(path.join(__dirname, '../build/Release/tsinterop.node'));
}catch(err){
    console.log("error: ",err);
}
export const Init = cppInterop.Init;
export const unInit = cppInterop.unInit;
export const SetCallBack = cppInterop.SetCallBack;
export const LoadMutationFile = cppInterop.LoadMutationFile;
export const StartTranscribing = cppInterop.StartTranscribing;
export const StopTranscribing = cppInterop.StopTranscribing;
