// Include default uefi header files
#include <efi.h>
#include <efilib.h>

// Main function that will be executed first
EFI_STATUS efi_main (EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) 
{

    // This var will be used for Status of the tasks that we will be
    EFI_STATUS Status;

    // This contains Keyboard Inputs
    EFI_INPUT_KEY Key;

    //Store the system table
    ST = SystemTable;

    // Print Hello Universe to the console
    Status = ST->ConOut->OutputString(ST->ConOut, L"Hello Universe!\n\r");

    // If Printing failed, return
    if (EFI_ERROR(Status))
        return Status;

    // Empty the Console Input Buffer
    Status = ST->ConIn->Reset(ST->ConIn, FALSE);

    // Check the Status of above command
    if (EFI_ERROR(Status))
        return Status;

    // Poll For Key Input
    while ((Status = ST->ConIn->ReadKeyStroke(ST->ConIn, &Key)) == EFI_NOT_READY);

    // Exit to this Application
    return Status;

}
                        