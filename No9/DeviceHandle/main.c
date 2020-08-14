#include "efi.h"
#include "common.h"

void efi_main(void *ImageHandle __attribute__ ((unused)),
         struct EFI_SYSTEM_TABLE *SystemTable)
{
    struct EFI_LOADED_IMAGE_PROTOCOL *lip;
    struct EFI_DEVICE_PATH_PROTOCOL *dev_path;
    unsigned long long status;

    efi_init(SystemTable);
    cls();

    // ImageHandleのEFI_LOADIMAGE_PROTOCOL(lip)を取得
    // デバイスパスを調べてくれて取得する
    status = ST->BootServices->OpenProtocol(
        ImageHandle, &lip_guid, (void **)&lip, ImageHandle, NULL,
        EFI_OPEN_PROTOCOL_GET_PROTOCOL);
    assert(status, L"OpenProtocol(lip)");

    // lip->DeviceHandleのEFI_DEVICE_PATH_PROTOCOL(dev_path)を取得
    status = ST->BootServices->OpenProtocol(
        lip->DeviceHandle, &dpp_guid, (void **)&dev_path, ImageHandle,
        NULL, EFI_OPEN_PROTOCOL_GET_PROTOCOL);
    assert(status, L"OpenProtocol(dpp)");

    // dev_pathをテキストに変換し表示
    puts(L"dev_path: ");
    puts(DPTTP->ConvertDevicePathToText(dev_path, FALSE, FALSE));
    puts(L"\r\n");

    while (TRUE);
}
