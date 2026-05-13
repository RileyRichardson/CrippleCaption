"use strict";
var __createBinding = (this && this.__createBinding) || (Object.create ? (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    var desc = Object.getOwnPropertyDescriptor(m, k);
    if (!desc || ("get" in desc ? !m.__esModule : desc.writable || desc.configurable)) {
      desc = { enumerable: true, get: function() { return m[k]; } };
    }
    Object.defineProperty(o, k2, desc);
}) : (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    o[k2] = m[k];
}));
var __setModuleDefault = (this && this.__setModuleDefault) || (Object.create ? (function(o, v) {
    Object.defineProperty(o, "default", { enumerable: true, value: v });
}) : function(o, v) {
    o["default"] = v;
});
var __importStar = (this && this.__importStar) || (function () {
    var ownKeys = function(o) {
        ownKeys = Object.getOwnPropertyNames || function (o) {
            var ar = [];
            for (var k in o) if (Object.prototype.hasOwnProperty.call(o, k)) ar[ar.length] = k;
            return ar;
        };
        return ownKeys(o);
    };
    return function (mod) {
        if (mod && mod.__esModule) return mod;
        var result = {};
        if (mod != null) for (var k = ownKeys(mod), i = 0; i < k.length; i++) if (k[i] !== "default") __createBinding(result, mod, k[i]);
        __setModuleDefault(result, mod);
        return result;
    };
})();
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.activate = activate;
exports.deactivate = deactivate;
const vscode = __importStar(require("vscode"));
const cppInterop = __importStar(require("./bindings"));
const path_1 = __importDefault(require("path"));
let Transcribing = false;
function activate(context) {
    cppInterop.Init(path_1.default.join(__dirname, "models/english"));
    cppInterop.SetCallBack((line) => {
        const editor = vscode.window.activeTextEditor;
        if (!editor)
            return;
        editor.edit(editBuilder => {
            editBuilder.insert(editor.selection.active, line);
        });
    });
    const disposable = vscode.commands.registerCommand('cripplecaptions.helloWorld', () => {
        if (Transcribing) {
            cppInterop.StopTranscribing();
            Transcribing = false;
        }
        else {
            cppInterop.StartTranscribing();
            Transcribing = true;
        }
    });
    context.subscriptions.push(disposable);
}
class TranscriptionEvent {
    text;
}
function deactivate() {
    cppInterop.unInit();
}
function transcriptionCallback(event) {
    const editor = vscode.window.activeTextEditor;
    if (!editor)
        return;
    editor.edit(editBuilder => {
        editBuilder.insert(editor.selection.active, event.text);
    });
}
//# sourceMappingURL=extension.js.map