#ifndef _EFI_H_
#define _EFI_H_

#define EFI_FILE_MODE_READ      0x0000000000000001  /* 仕様書P508（2020.04.17） */
#define EFI_FILE_MODE_WRITE     0x0000000000000002
#define EFI_FILE_MODE_CREATE    0x8000000000000000

#define EFI_FILE_READ_ONLY      0x0000000000000001

//**************************************************************
// Attribute(SetAttribute()用置換マクロ)
//**************************************************************
#define EFI_BLACK           0x00
#define EFI_BLUE            0x01
#define EFI_GREEN           0x02
#define EFI_CYAN            0x03
#define EFI_RED             0x04
#define EFI_MAGENTA         0x05
#define EFI_BROWN           0x06
#define EFI_LIGHTGRAY       0x07
#define EFI_BRIGHT          0x08
#define EFI_DARKGRAY        0x08
#define EFI_LIGHTBLUE       0x09
#define EFI_LIGHTGREEN      0x0A
#define EFI_LIGHTCYAN       0x0B
#define EFI_LIGHTRED        0x0C
#define EFI_LIGHTMAGENTA    0x0D
#define EFI_YELLOW          0x0E
#define EFI_WHITE           0x0F

#define EFI_BACKGROUND_BLACK        0x00
#define EFI_BACKGROUND_BLUE         0x10
#define EFI_BACKGROUND_GREEN        0x20
#define EFI_BACKGROUND_CYAN         0x30
#define EFI_BACKGROUND_RED          0x40
#define EFI_BACKGROUND_MAGENTA      0x50
#define EFI_BACKGROUND_BROWN        0x60
#define EFI_BACKGROUND_LIGHTGRAY    0x70
// QueryMode()用
#define EFI_SUCCESS                 0
#define EFI_ERROR                   0x8000000000000000
#define EFI_UNSUPPORTED             (EFI_ERROR | 3)

#define EFI_OPEN_PROTOCOL_BY_HANDLE_PROTOCOL    0x00000001
#define EFI_OPEN_PROTOCOL_GET_PROTOCOL          0x00000002
#define EFI_OPEN_PROTOCOL_TEST_PROTOCOL         0x00000004
#define EFI_OPEN_PROTOCOL_BY_CHID_CONTROLLER    0x00000008
#define EFI_OPEN_PROTOCOL_BY_DRIVER             0x00000010
#define EFI_OPEN_PROTOCOL_EXCLUSIVE             0x00000020

/* キー入力の定義 */
struct EFI_INPUT_KEY {
    unsigned short ScanCode;    // Unicode外のキー入力に使用。スキャンコード
    unsigned short UnicodeChar; // Unicode内のキー入力時に使用。ユニコード値
};

struct EFI_GUID {
    unsigned int Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
};
// 詳細は仕様書のP282を参照
enum EFI_MEMORY_TYPE {
    EfiReservedMemoryType,
    EfiLoaderCode,
    EfiLoaderData,
    EfiBootServicesCode,
    EfiBootServicesData,
    EfiRuntimeServicesCode,
    EfiRuntimeServicesData,
    EfiConventionalMemory,
    EfiUnusableMemory,
    EfiACPIReclaimMemory,
    EfiACPIMemoryNVS,
    EfiMemoryMappedIO,
    EfiMemoryMappedIOPortSpace,
    EfiPalCode,
    EfiMaxMemoryType
};

struct EFI_DEVICE_PATH_PROTOCOL {
    unsigned char Type;
    unsigned char SubType;
    unsigned char Length[2];
};

/* システムテーブルの定義 */
struct EFI_SYSTEM_TABLE {
    char _buf1[44];
    /* キー入力のプロトコル */
    struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL {
        unsigned long long _buf;
        unsigned long long (*ReadKeyStroke)(
            struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL *This,
            struct EFI_INPUT_KEY *Key);
        void *WaitForKey;
    } *ConIn;

    unsigned long long _buf2;
    
    /* 画面出力のプロトコル */
    struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL {
        unsigned long long _buf;
        unsigned long long (*OutputString)(
            struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
            unsigned short *String);
        unsigned long long (*TestString)(
            struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
            unsigned short *String);    /* 判定したい文字列の先頭アドレスを指定 */
        unsigned long long (*QueryMode)(
            struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
            unsigned long long ModeNumber,  /* 行列数の確認したいモード番号を指定 */
            unsigned long long *Columns,    /* 列数を保存する変数へのポインタ */
            unsigned long long *Rows);      /* 行数を保存する変数へのポインタ */
        unsigned long long (*SetMode)(
            struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
            unsigned long long ModeNumber); // テキストモード番号
        unsigned long long (*SetAttribute)(
            struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
            unsigned long long Attribute);    // 文字色と文字の背景色を設定
        unsigned long long (*ClearScreen)(
            struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This);
        unsigned long long _buf4[2];
        struct SIMPLE_TEXT_OUTPUT_MODE {
            int MaxMode;        // コンソール番号で使用できるモード番号の最大値
            int Mode;           // 現在のモード番号
            int Attribute;      // 現在設定されている属性値 (文字色・背景色)
            int CursorColumn;   // カーソル位置（列）
            int CursorRow;      // カーソル位置（行）
            unsigned char CursorVisible;    // 現在のカーソル表示設定(表示=1/非表示=0)
        } *Mode;
    } *ConOut;
    unsigned long long _buf3[3];
    /* ブートサービスプロトコル（ブートローダ関連） */
    struct EFI_BOOT_SERVICES {
        char _buf1[24];
        /*                          */
        /* Task Priority Services   */
        /*                          */
        unsigned long long _buf2[2];
        /*                          */
        /* Memory Services          */
        /*                          */
        unsigned long long _buf3[5];

        /*                          */
        /* Event & Timer Services   */
        /*                          */
        unsigned long long _buf4[2];
        unsigned long long (*WaitForEvent)(
            unsigned long long NumberOfEvents,
            void **Event,
            unsigned long long *Index);
        unsigned long long _buf4_2[3];
		/*                              */
		/* Protocol Handler Services    */
		/*                              */
		unsigned long long _buf5[9];
		/*                              */
		/* Image Services               */
		/*                              */
        unsigned long long (*LoadImage)(
            unsigned char BootPolicy,
            void *ParentImageHandle,
            struct EFI_DEVICE_PATH_PROTOCOL *DevicePath,
            void *SourceBuffer,
            unsigned long long SourceSize,
            void **ImageHandle);
        unsigned long long _buf6[4];
		/*                              */
		/* Miscellaneous Services       */
		/*                              */
        unsigned long long _buf7[2];
        unsigned long long (*SetWatchdogTimer)(
            unsigned long long Timeout,
            unsigned long long WatchdogCode,
            unsigned long long DataSize,
            unsigned short *WatchdogData);

        //
        // DriverSupport Services
        //
        unsigned long long _buf8[2];
     
        //
        // Open and Close Protocol Services
        //
        unsigned long long (*OpenProtocol)(
            void *Handle,
            struct EFI_GUID *Protocol,
            void **Interface,
            void *AgentHandle,
            void *ControllerHandle,
            unsigned int Attributes);
        unsigned long long _buf9[2];

        //
        // Library Services
        //
        unsigned long long _buf10[2];
        unsigned long long (*LocateProtocol)(   /* プロトコルの取得に使用 */
            struct EFI_GUID *Protocol,
            void *Registration,
            void **Interface);
        unsigned long long _buf10_2[2];
        //
        // 32-bit CRC Services
        //
        unsigned long long _buf11;
        //
        // Miscellaneous Services
        //
        unsigned long long _buf12[3]; 
    } *BootServices;
};

struct EFI_GRAPHICS_OUTPUT_BLT_PIXEL {
    unsigned char Blue;
    unsigned char Green;
    unsigned char Red;
    unsigned char Reserved;
};

struct EFI_GRAPHICS_OUTPUT_PROTOCOL {
    unsigned long long _buf[3];
    struct EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE {
        unsigned int MaxMode;
        unsigned int Mode;
        struct EFI_GRAPHICS_OUTPUT_MODE_INFORMATION {
            unsigned int Version;
            unsigned int HorizontalResolution;
            unsigned int VerticalResolution;
            enum EFI_GRAPHICS_PIXEL_FORMAT {
                PixelRedGreenBlueReserved8BitPerColor,
                PixelBlueGreenRedReserved8BitPerColor,
                PixelBitMask,
                PixelBltOnly,
                PixelFormatMax
            } PixelFormat;
        } *Info;
        unsigned long long SizeOfInfo;
        unsigned long long FrameBufferBase;
    } *Mode;
};

/* マウスの移動量・状態の管理構造体 */
struct EFI_SIMPLE_POINTER_STATE {
    int RelativeMovementX;      /* x座標の相対移動量 */
    int RelativeMovementY;      /* y座標の相対移動量 */
    int RelativeMovementZ;      /* z座標の相対移動量 */
    unsigned char LeftButton;   /* 左ボタンの状態(押してる=1、押してない=0) */
    unsigned char RightButton;  /* 右ボタンの状態(押してる=1、押してない=0) */
};

struct EFI_SIMPLE_POINTER_PROTOCOL {
    unsigned long long (*Reset)(    /* マウスのリセット */
        struct EFI_SIMPLE_POINTER_PROTOCOL *This,
        unsigned char ExtendedVerification);    /* ファームウェア依存の拡張検査を行う(TRUE) */
    unsigned long long (*GetState)(     /* 状態の取得 */
        struct EFI_SIMPLE_POINTER_PROTOCOL *This,
        struct EFI_SIMPLE_POINTER_STATE *State);    /* マウスの状態を指定されたポインタ変数に格納 */
    void *WaitForInput;
};

struct EFI_FILE_INFO {
    unsigned char _buf[80];
    unsigned short FileName[];
};

/* ファイル、ディレクトリのエントリの管理 */
struct EFI_FILE_PROTOCOL {
    unsigned long long _buf;
    unsigned long long (*Open)(struct EFI_FILE_PROTOCOL *This,  /* ファイルのEFI_FILE_PROTOCOLを取得 */
                    struct EFI_FILE_PROTOCOL **NewHandle,
                    unsigned short *FileName,
                    unsigned long long OpenMode,
                    unsigned long long Attributes);
    unsigned long long (*Close)(struct EFI_FILE_PROTOCOL *This);    /* ファイル、ディレクトリに対しての処理の後実行 */
    unsigned long long _buf2;
    /* ファイル、ディレクトリ名・ファイルのデータの取得に使用 */
    unsigned long long (*Read)(struct EFI_FILE_PROTOCOL *This,
                    unsigned long long *BufferSize,   /* 指定のポインタ変数にデータサイズを格納 */
                    void *Buffer);      /* readしてデータを指定のバッファの先頭アドレスから格納 */
    unsigned long long (*Write)(struct EFI_FILE_PROTOCOL *This,
                    unsigned long long *BufferSize,
                    void *Buffer);
    unsigned long long _buf3[4];
    unsigned long long (*Flush)(struct EFI_FILE_PROTOCOL *This);
};

struct EFI_SIMPLE_FILE_SYSTEM_PROTOCOL {
    unsigned long long Revision;
    unsigned long long (*OpenVolume)(       /* ルートディレクリを呼び出す */
        struct EFI_SIMPLE_FILE_SYSTEM_PROTOCOL *This,
        struct EFI_FILE_PROTOCOL **Root);
};

struct EFI_KEY_STATE {  // キー入力時の状態を定義する
    unsigned int KeyShiftState;     // Shiftキーの状態
    unsigned char KeyToggleState;   // キーボードのトグルの状態(ScrollLock,NumLock,CapsLock)
};

struct EFI_KEY_DATA {
    struct EFI_INPUT_KEY Key;
    struct EFI_KEY_STATE KeyState;
};

struct EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL {
    unsigned long long (*Reset)(
        struct EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL *This,
        unsigned char ExtendedVerification);
    unsigned long long (*ReadKeyStrokeEx)(
        struct EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL *This,
        struct EFI_KEY_DATA *KeyData);
    void *WaitForKeyEx;
    unsigned long long (*SetState)(
        struct EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL *This,
        unsigned char *KeyToggleState);
    unsigned long long (*RegisterKeyNotify)(    // 特定のキー入力で返す関数を登録できる
        struct EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL *This,
        struct EFI_KEY_DATA *KeyData,   // イベントとして使うキーを登録
        unsigned long long (*KeyNotificationFunction)(  // 通知関数
            struct EFI_KEY_DATA *KeyData),
        void **NotifyHandle);   // 登録解除時に返すユニークなハンドル
    unsigned long long (*UnregisterKeyNotify)(
        struct EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL *This,
        void *NotificationHandle);
};

struct EFI_LOADED_IMAGE_PROTOCOL {
    unsigned int Revision;
    void *ParentHandle;
    struct EFI_SYSTEM_TABLE *SystemTable;
    // Source location of the image
    void *DeviceHandle;
    struct EFI_DEVICE_PATH_PROTOCOL *FilePath;
    void *Reserved;
    // Image’s load options
    unsigned int LoadOptionsSize;
    void *LoadOptions;
    // Location where image was loaded
    void *ImageBase;
    unsigned long long ImageSize;
    enum EFI_MEMORY_TYPE ImageCodeType;
    enum EFI_MEMORY_TYPE ImageDataType;
    unsigned long long (*Unload)(void *ImageHandle);
};

struct EFI_DEVICE_PATH_TO_TEXT_PROTOCOL {
    unsigned long long _buf;
    unsigned short *(*ConvertDevicePathToText)(
        const struct EFI_DEVICE_PATH_PROTOCOL* DeviceNode,
        unsigned char DisplayOnly,
        unsigned char AllowShortcuts);
};

struct EFI_DEVICE_PATH_FROM_TEXT_PROTOCOL {
    unsigned long long _buf;
    struct EFI_DEVICE_PATH_PROTOCOL *(*ConvertTextToDevicePath) (
        const unsigned short *TextDevicePath);
};

extern struct EFI_SYSTEM_TABLE *ST;
extern struct EFI_GRAPHICS_OUTPUT_PROTOCOL *GOP;
extern struct EFI_SIMPLE_POINTER_PROTOCOL *SPP;
extern struct EFI_SIMPLE_FILE_SYSTEM_PROTOCOL *SFSP;
extern struct EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL *STIEP;
extern struct EFI_DEVICE_PATH_TO_TEXT_PROTOCOL *DPTTP;
extern struct EFI_DEVICE_PATH_FROM_TEXT_PROTOCOL *DPFTP;
extern struct EFI_GUID lip_guid;
extern struct EFI_GUID dpp_guid;

void efi_init(struct EFI_SYSTEM_TABLE *SystemTable);
 
#endif
