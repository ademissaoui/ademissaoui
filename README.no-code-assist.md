# Workspace: no-code-assist-disabled

This workspace disables editor code-assist features (IntelliSense, suggestions, hover, inline suggestions, parameter hints, quick suggestions, word-based suggestions, suggestion-on-trigger-characters, lightbulb, and format-on-type) so you can work without automated completions.

How to use
- Open this workspace file in VS Code: `no-code-assist-disabled.code-workspace` (File → Open Workspace...).

What this workspace sets
- `editor.quickSuggestions`: { other: false, comments: false, strings: false }
- `editor.suggestOnTriggerCharacters`: false
- `editor.wordBasedSuggestions`: "off"
- `editor.parameterHints.enabled`: false
- `editor.hover.enabled`: false
- `editor.inlineSuggest.enabled`: false
- `editor.lightbulb.enabled`: "off"
- `editor.formatOnType`: false
- `editor.suggest.showWords`: false
- `extensions.ignoreRecommendations`: true
- `typescript.disableAutomaticTypeAcquisition`: true

How to re-enable assistance
1. Open the workspace file you normally use (or edit workspace settings).
2. Either remove or change the keys above to their re-enabled values. Recommended settings to restore typical assistance:

```json
"editor.quickSuggestions": { "other": true, "comments": true, "strings": true },
"editor.suggestOnTriggerCharacters": true,
"editor.wordBasedSuggestions": "allDocuments",
"editor.parameterHints.enabled": true,
"editor.hover.enabled": true,
"editor.inlineSuggest.enabled": true,
"editor.lightbulb.enabled": "on",
"editor.formatOnType": true,
"extensions.ignoreRecommendations": false
```

Alternatively, open your normal workspace or user settings. If you previously modified `.vscode/settings.json`, review its backup files (`.vscode/settings.json.backup` or `no-code-assist.code-workspace.backup`) in the repository root.
# Workspace: no-code-assist

This workspace disables editor code-assist features (IntelliSense, suggestions, hover, inline suggestions, parameter hints, quick suggestions, etc.) by applying workspace settings.

Files created:

- `.vscode/settings.json` — workspace settings applied when you open this folder in VS Code.
- `no-code-assist.code-workspace` — a .code-workspace file you can open directly to load the same settings.

How to re-enable assistance

1. Open `.vscode/settings.json` and change the relevant settings back to `true` or remove the file.
2. Or open `no-code-assist.code-workspace` and remove/modify the settings under the `settings` key.
3. To re-enable extension-specific features, re-open the Extensions view and enable the extensions you want; you can also set `"extensions.ignoreRecommendations": false`.

Notes

- These settings are workspace-level and will not change your global user settings.
- If a language extension provides its own engine (e.g., TypeScript server or C/C++ language server), you may need to adjust that extension's settings separately.
