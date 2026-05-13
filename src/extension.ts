import * as vscode from 'vscode';
import * as cppInterop from './bindings';
import path from 'path';
let Transcribing = false;
export function activate(context: vscode.ExtensionContext) {
	cppInterop.Init(path.join(__dirname,"models/english"));
	cppInterop.SetCallBack((line:string)=>{
		const editor = vscode.window.activeTextEditor;
		if (!editor) return;
		editor.edit(editBuilder => {
			editBuilder.insert(editor.selection.active, line);
		});
	});
	const disposable = vscode.commands.registerCommand('cripplecaptions.helloWorld', () => {
		if(Transcribing){
			cppInterop.StopTranscribing();
			Transcribing = false;
		}else{
			cppInterop.StartTranscribing();
			Transcribing = true;
		}
	});
	context.subscriptions.push(disposable);
}


class TranscriptionEvent{
	text: string;
}
export function deactivate() {
	cppInterop.unInit();
}
function transcriptionCallback(event: TranscriptionEvent){
	const editor = vscode.window.activeTextEditor;
	if (!editor) return;
	editor.edit(editBuilder => {
		editBuilder.insert(editor.selection.active, event.text);
	});
}
