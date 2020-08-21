#include "efi.h"
#include "common.h"

void timer_callback(void *event __attribute__ ((unused)),
            void *context __attribute__ ((unused)))
{
    puts(L"//nemui...(~_~)//");
}

void efi_main(void *ImageHandle __attribute__ ((unused)),
          struct EFI_SYSTEM_TABLE *SystemTable)
{
    unsigned long long status;
    void *tevent;

    efi_init(SystemTable);
    cls();
    
    // タイマーイベントを作成し、teventへ格納
    status = ST->BootServices->CreateEvent(EVT_TIMER | EVT_NOTIFY_SIGNAL,
                            TPL_CALLBACK, timer_callback,
                            NULL, &tevent);
    assert(status, L"CreateEvent");

    // teventへ１秒のトリガー時間を設定
    status = ST->BootServices->SetTimer(tevent, TimerPeriodic,
                        10000000);
    assert(status, L"SetTimer");

    while (TRUE);
}
