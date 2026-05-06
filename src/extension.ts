import * as vscode from 'vscode';

export function activate(context: vscode.ExtensionContext) {
	const disposable = vscode.commands.registerCommand('cripplecaptions.helloWorld', () => {

		
	});

	context.subscriptions.push(disposable);
}


class TranscriptionEvent{
	text: string;
}
export function deactivate() {}
function transcriptionCallback(event: TranscriptionEvent){
	const editor = vscode.window.activeTextEditor;
	if (!editor) return;
	editor.edit(editBuilder => {
		editBuilder.insert(editor.selection.active, event.text);
	});
}