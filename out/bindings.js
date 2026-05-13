"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.StopTranscribing = exports.StartTranscribing = exports.LoadMutationFile = exports.SetCallBack = exports.unInit = exports.Init = void 0;
const path_1 = __importDefault(require("path"));
let cppInterop = null;
try {
    cppInterop = require(path_1.default.join(__dirname, '../build/Release/tsinterop.node'));
}
catch (err) {
    console.log("error: ", err);
}
exports.Init = cppInterop.Init;
exports.unInit = cppInterop.unInit;
exports.SetCallBack = cppInterop.SetCallBack;
exports.LoadMutationFile = cppInterop.LoadMutationFile;
exports.StartTranscribing = cppInterop.StartTranscribing;
exports.StopTranscribing = cppInterop.StopTranscribing;
//# sourceMappingURL=bindings.js.map