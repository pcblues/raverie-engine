// MIT Licensed (see LICENSE.md).
#pragma once

namespace Zero
{
namespace Events
{
// This event occurs in the middle of OsShell update before we process Os
// messages
DeclareEvent(Cut);
DeclareEvent(Copy);
DeclareEvent(Paste);
DeclareEvent(OsShellUpdate);
DeclareEvent(FileDialogComplete);
} // namespace Events

class OsWindow;
struct FileDialogConfig;

/// Os Shell interface used to provide abstract platform user interface
/// functionality. Used to manage mouse, keyboard, and clipboard functionality.
class OsShell : public System
{
public:
  ZilchDeclareType(OsShell, TypeCopyMode::ReferenceType);

  OsShell();

  /// System interface
  cstr GetName() override;
  void Update(bool debugger) override;

  /// Set the cursor for the mouse.
  void SetMouseCursor(Cursor::Enum cursorId);

  /// Scan for new input devices and register them with Zero.
  void ScanInputDevices();

  // Internal

  /// Platform specific shell
  Shell mShell;
};

class ClipboardEvent : public Event
{
public:
  ZilchDeclareType(ClipboardEvent, TypeCopyMode::ReferenceType);
  void Clear();
  void SetText(StringParam text);
  String GetText();

  String mText;

  // This is used internally to indicate the clipboard event was handled
  // This does NOT indicate that text or any data was set on it
  bool mHandled = false;
};

/// Files have been selected by the File Dialog.
class OsFileSelection : public Event
{
public:
  ZilchDeclareType(OsFileSelection, TypeCopyMode::ReferenceType);
  bool Success;
  Array<String> Files;
};

/// FileDialogConfig is used to configure the Open File Dialog
/// and the Save File Dialog.
/// Note that the config may only be used ONCE because it will be automatically
/// deleted at the end of the OpenFile call.
struct FileDialogConfig : public FileDialogInfo
{
  // The default event name is Events::FileDialogComplete.
  String EventName;
  HandleOf<Object> CallbackObject;

  static FileDialogConfig* Create();

private:
  FileDialogConfig();
  static void Callback(Array<String>& files, void* userData);
};

} // namespace Zero
