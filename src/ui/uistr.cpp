#include <string>
#include <map>

#include "file.h"
#include "cfg.h"
#include "type.h"
#include "util.h"
#include "uistr.h"

std::map<std::pair<std::string, int>, std::string> ui::strings;

static void addUIString(const std::string& _name, int ind, const std::string& _str)
{
    ui::strings[std::make_pair(_name, ind)] = _str;
}

static void loadTranslationFile(const std::string& path)
{
    if(fs::fileExists(path))
    {
        fs::dataFile lang(path);
        while(lang.readNextLine(true))
        {
            std::string name = lang.getName();
            int ind = lang.getNextValueInt();
            std::string str = lang.getNextValueStr();
            addUIString(name, ind, str);
        }
    }
}

static std::string getFilename(int lang)
{
    std::string filename;
    switch(lang)
    {
        /*case SetLanguage_JA:
            filename = "ja.txt";
            break;

        case SetLanguage_ENUS:
            filename = "en-US.txt";
            break;

        case SetLanguage_FR:
            filename = "fr.txt";
            break;

        case SetLanguage_DE:
            filename = "de.txt";
            break;

        case SetLanguage_IT:
            filename = "it.txt";
            break;

        case SetLanguage_ES:
            filename = "es.txt";
            break;

        case SetLanguage_ZHCN:
        case SetLanguage_ZHHANS:
            filename = "zh-CN.txt";
            break;*/

        case SetLanguage_KO:
            filename = "ko.txt";
            break;

        /*case SetLanguage_NL:
            filename = "nl.txt";
            break;

        case SetLanguage_PT:
            filename = "pt.txt";
            break;

        case SetLanguage_RU:
            filename = "ru.txt";
            break;

        case SetLanguage_ZHTW:
        case SetLanguage_ZHHANT:
            filename += "zh-TW.txt";
            break;

        case SetLanguage_ENGB:
            filename = "en-GB.txt";
            break;

        case SetLanguage_FRCA:
            filename = "fr-CA.txt";
            break;

        case SetLanguage_ES419:
            filename = "es-419.txt";
            break;

        case SetLanguage_PTBR:
            filename = "pt-BR.txt";
            break;*/
    }
    return filename;
}

void ui::initStrings()
{
    addUIString("author", 0, "NULL");
    addUIString("helpUser", 0, "[A] 선택   [Y] 모든 세이브 덤프   [X] 사용자 옵션");
    addUIString("helpTitle", 0, "[A] 선택   [L][R] 점프   [Y] 즐겨찾기   [X] 제목 옵션  [B] 뒤로");
    addUIString("helpFolder", 0, "[A] 선택  [Y] 복원  [X] 삭제   [ZR] 업로드  [B] 닫기");
    addUIString("helpSettings", 0, "[A] 전환   [X] 기본   [B] 뒤로");

    //Y/N On/Off
    addUIString("dialogYes", 0, "예 [A]");
    addUIString("dialogNo", 0, "아니오 [B]");
    addUIString("dialogOK", 0, "확인 [A]");
    addUIString("settingsOn", 0, ">켬>");
    addUIString("settingsOff", 0, "끔");
    addUIString("holdingText", 0, "(길게 누르기) ");
    addUIString("holdingText", 1, "(계속 누르기) ");
    addUIString("holdingText", 2, "(거의 완료!) ");

    //Confirmation Strings
    addUIString("confirmBlacklist", 0, "블랙리스트에 #%s# 을(를) 추가하겠습니까?");
    addUIString("confirmOverwrite", 0, "#%s#을(를) 덮어쓰시겠습니까?");
    addUIString("confirmRestore", 0, "#%s#을(를) 복원하겠습니까?");
    addUIString("confirmDelete", 0, "#%s#을(를) 영구적으로 삭제하겠습니까?");
    addUIString("confirmCopy", 0, "#%s#을(를) #%s#에 복사하겠습니까?");
    addUIString("confirmDeleteSaveData", 0, "경고*: 진행시 #%s#에 대한 세이브 데이터가 *시스템에서* 지워집니다. 정말 하겠습니까?");
    addUIString("confirmResetSaveData", 0, "경고*: 진행시 이 게임의 세이브 데이터가 *리셋됩니다*. 정말 하겠습니까?");
    addUIString("confirmCreateAllSaveData", 0, "이 시스템에서 #%s#에 대한 모든 세이브 데이터를 생성하겠습니까? 검색된 타이틀 수에 따라 시간이 걸릴 수 있습니다.");
    addUIString("confirmDeleteBackupsTitle", 0, "#%s#에 대한 모든 백업을 삭제하겠습니까?");
    addUIString("confirmDeleteBackupsAll", 0, "모든 게임에 대한 세이브 백업을 삭제하겠습니까?");
    addUIString("confirmDriveOverwrite", 0, "드라이브에서 이 백업을 다운로드하면 SD 카드에 있는 백업을 덮어씁니다. 계속합니까?");

    //Save Data related strings
    addUIString("saveDataNoneFound", 0, "#%s#의 세이브 데이터를 찾을 수 없습니다!");
    addUIString("saveDataCreatedForUser", 0, "%s의 세이브 데이터 저장!");
    addUIString("saveDataCreationFailed", 0, "세이브 데이터 생성 실패!");
    addUIString("saveDataResetSuccess", 0, "#%s#의 재설정을 위해 저장합니다!");
    addUIString("saveDataDeleteSuccess", 0, "#%s#의 세이브 데이터가 삭제되었습니다!");
    addUIString("saveDataExtendSuccess", 0, "#%s#의 세이브 데이터가 확장되었습니다!");
    addUIString("saveDataExtendFailed", 0, "세이브 데이터 확장에 실패했습니다.");
    addUIString("saveDataDeleteAllUser", 0, "*%s의 모든 세이브 데이터를 삭제하겠습니까?*");
    addUIString("saveDataBackupDeleted", 0, "#%s#이(가) 삭제되었습니다.");
    addUIString("saveDataBackupMovedToTrash", 0, "#%s#이(가) 휴지통으로 이동되었습니다.");
    addUIString("saveTypeMainMenu", 0, "기기");
    addUIString("saveTypeMainMenu", 1, "BCAT");
    addUIString("saveTypeMainMenu", 2, "캐시");
    addUIString("saveTypeMainMenu", 3, "시스템");
    addUIString("saveTypeMainMenu", 4, "시스템 BCAT");
    addUIString("saveTypeMainMenu", 5, "임시");
    //This is redundant. Need to merge and use one or the other...
    addUIString("saveDataTypeText", 0, "시스템");
    addUIString("saveDataTypeText", 1, "어카운트");
    addUIString("saveDataTypeText", 2, "BCAT");
    addUIString("saveDataTypeText", 3, "기기");
    addUIString("saveDataTypeText", 4, "임시");
    addUIString("saveDataTypeText", 5, "캐시");
    addUIString("saveDataTypeText", 6, "시스템 BCAT");

    //Internet Related
    addUIString("onlineErrorConnecting", 0, "연결 오류!");
    addUIString("onlineNoUpdates", 0, "사용 가능한 업데이트가 없습니다.");

    //File mode menu strings
    addUIString("fileModeMenu", 0, "Copy To ");
    addUIString("fileModeMenu", 1, "삭제");
    addUIString("fileModeMenu", 2, "이름 변경");
    addUIString("fileModeMenu", 3, "폴더 생성");
    addUIString("fileModeMenu", 4, "속성");
    addUIString("fileModeMenu", 5, "닫기");
    addUIString("fileModeMenu", 6, "경로에 필터 추가");
    addUIString("fileModeMenuMkDir", 0, "새로 만들기");

    //New folder pop menu strings
    addUIString("folderMenuNew", 0, "새 백업");

    //File mode properties string
    addUIString("fileModeFileProperties", 0, "경로: %s\n크기: %s");
    addUIString("fileModeFolderProperties", 0, "경로: %s\n하위 폴더: %u\n파일 수: %u\n전체 크기: %s");

    //Settings menu
    addUIString("settingsMenu", 0, "휴지통 비우기");
    addUIString("settingsMenu", 1, "버전 업데이트");
    addUIString("settingsMenu", 2, "세이브 데이터 저장 폴더 설정");
    addUIString("settingsMenu", 3, "블랙리스트 타이틀 이름 변경");
    addUIString("settingsMenu", 4, "모든 세이브 백업 삭제");
    addUIString("settingsMenu", 5, "유저 및 세이브 데이터 포함: ");
    addUIString("settingsMenu", 6, "복원 시 자동 백업: ");
    addUIString("settingsMenu", 7, "백업 이름 자동 지정: ");
    addUIString("settingsMenu", 8, "오버클럭/CPU 부스트: ");
    addUIString("settingsMenu", 9, "삭제하려면 길게 누르기: ");
    addUIString("settingsMenu", 10, "복원하려면 길게 누르기: ");
    addUIString("settingsMenu", 11, "덮어쓰려면 길게 누르기: ");
    addUIString("settingsMenu", 12, "강제 마운트: ");
    addUIString("settingsMenu", 13, "어카운트 시스템 저장: ");
    addUIString("settingsMenu", 14, "시스템 세이브 쓰기 활성화: ");
    addUIString("settingsMenu", 15, "FS 명령 직접 주입: ");
    addUIString("settingsMenu", 16, "ZIP 파일로 세이브 내보내기: ");
    //addUIString("settingsMenu", 17, "언어 고정(한국어): ");
    addUIString("settingsMenu", 17, "휴지통 활성화: ");
    addUIString("settingsMenu", 18, "정렬 방법: ");
    addUIString("settingsMenu", 19, "애니메이션 스케일: ");
    addUIString("settingsMenu", 20, "드라이브/Webdav로 자동 업로드: ");

    //Main menu
    addUIString("mainMenuSettings", 0, "설정");
    addUIString("mainMenuExtras", 0, "고급");

    // Translator in main page
    addUIString("translationMainPage", 0, "번역: ");

    //Loading page
    addUIString("loadingStartPage", 0, "로딩 중...");

    //Sort Strings for ^
    addUIString("sortType", 0, "알파벳 순");
    addUIString("sortType", 1, "플레이 타임");
    addUIString("sortType", 2, "마지막 실행");

    //Extras
    addUIString("extrasMenu", 0, "SD에서 SD 브라우저로 이동");
    addUIString("extrasMenu", 1, "BIS: ProdInfo");
    addUIString("extrasMenu", 2, "BIS: Safe");
    addUIString("extrasMenu", 3, "BIS: System");
    addUIString("extrasMenu", 4, "BIS: User");
    addUIString("extrasMenu", 5, "보류 중인 업데이트 제거");
    addUIString("extrasMenu", 6, "프로세스 종료");
    addUIString("extrasMenu", 7, "시스템 세이브 마운트");
    addUIString("extrasMenu", 8, "타이틀 재검색");
    addUIString("extrasMenu", 9, "RomFS 프로세스 마운트");
    addUIString("extrasMenu", 10, "세이브 폴더 백업");
    //addUIString("extrasMenu", 11, "*[관리자]* 한국어 고정");

    //User Options
    addUIString("userOptions", 0, "유저 덤프: ");
    addUIString("userOptions", 1, "세이브 데이터 생성");
    addUIString("userOptions", 2, "모든 세이브 데이터 생성");
    addUIString("userOptions", 3, "모든 유저 데이터 삭제");

    //Title Options
    addUIString("titleOptions", 0, "상세 정보");
    addUIString("titleOptions", 1, "블랙리스트");
    addUIString("titleOptions", 2, "추출 폴더 변경");
    addUIString("titleOptions", 3, "파일 모드에서 열기");
    addUIString("titleOptions", 4, "모든 세이브 백업 제거");
    addUIString("titleOptions", 5, "세이브 데이터 리셋");
    addUIString("titleOptions", 6, "세이브 데이터 삭제");
    addUIString("titleOptions", 7, "세이브 데이터 확장");
    addUIString("titleOptions", 8, "SVI 내보내기");

    //Thread Status Strings
    addUIString("threadStatusCreatingSaveData", 0, "#%s#의 세이브 데이터 생성 중...");
    addUIString("threadStatusCopyingFile", 0, "'#%s#' 복사 중...");
    addUIString("threadStatusDeletingFile", 0, "삭제 중...");
    addUIString("threadStatusOpeningFolder", 0, "'#%s#'을(를) 여는 중...");
    addUIString("threadStatusAddingFileToZip", 0, "'#%s#'을(를) ZIP에 추가하는 중...");
    addUIString("threadStatusDecompressingFile", 0, "'#%s#' 압축 해제 중...");
    addUIString("threadStatusDeletingSaveData", 0, "#%s#의 세이브 데이터 삭제 중...");
    addUIString("threadStatusExtendingSaveData", 0, "#%s#의 세이브 데이터 확장 중...");
    addUIString("threadStatusCreatingSaveData", 0, "#%s#의 세이브 데이터 생성 중...");
    addUIString("threadStatusResettingSaveData", 0, "세이브 데이터 리셋 중...");
    addUIString("threadStatusDeletingUpdate", 0, "대기 중인 업데이트 삭제 중...");
    addUIString("threadStatusCheckingForUpdate", 0, "업데이트 확인 중...");
    addUIString("threadStatusDownloadingUpdate", 0, "업데이트 다운로드 중...");
    addUIString("threadStatusGetDirProps", 0, "폴더 속성 가져오기...");
    addUIString("threadStatusPackingJKSV", 0, "JKSV 폴더 내용을 ZIP에 쓰는 중...");
    addUIString("threadStatusSavingTranslations", 0, "마스터 파일 저장 중...");
    addUIString("threadStatusCalculatingSaveSize", 0, "세이브 데이터 크기 계산 중...");
    addUIString("threadStatusUploadingFile", 0, "#%s# 업로드 중...");
    addUIString("threadStatusDownloadingFile", 0, "#%s# 다운로드 중...");
    addUIString("threadStatusCompressingSaveForUpload", 0, "업로드를 위해 #%s# 압축 중...");

    //Random leftover pop-ups
    addUIString("popCPUBoostEnabled", 0, "ZIP을 위한 CPU 부스트가 활성화되었습니다.");
    addUIString("popErrorCommittingFile", 0, "저장할 파일을 커밋하는 동안 오류가 발생했습니다!");
    addUIString("popZipIsEmpty", 0, "ZIP 파일이 비어 있습니다!");
    addUIString("popFolderIsEmpty", 0, "폴더가 비어 있습니다!");
    addUIString("popSaveIsEmpty", 0, "세이브 데이터가 비어 있습니다!");
    addUIString("popProcessShutdown", 0, "#%s#이(가) 성공적으로 종료되었습니다.");
    addUIString("popAddedToPathFilter", 0, "'#%s#'이(가) 경로 필터에 추가되었습니다.");
    addUIString("popChangeOutputFolder", 0, "#%s#이(가) #%s#로 변경되었습니다.");
    addUIString("popChangeOutputError", 0, "#%s#에 잘못된 또는 ASCII가 아닌 문자가 포함되어 있습니다.");
    addUIString("popTrashEmptied", 0, "휴지통을 비웠습니다.");
    addUIString("popSVIExported", 0, "SVI를 내보냈습니다.");
    addUIString("popDriveStarted", 0, "구글 드라이브가 성공적으로 시작되었습니다.");
    addUIString("popDriveFailed", 0, "구글 드라이브 시작에 실패했습니다.");
    addUIString("popRemoteNotActive", 0, "원격을 사용할 수 없습니다.");
    addUIString("popWebdavStarted", 0, "Webdav가 성공적으로 시작되었습니다.");
    addUIString("popWebdavFailed", 0, "Webdav를 시작하지 못했습니다.");

    //Keyboard hints
    addUIString("swkbdEnterName", 0, "새 이름 작성");
    addUIString("swkbdSaveIndex", 0, "캐시 인덱스 작성");
    addUIString("swkbdSetWorkDir", 0, "새 추출 경로 설정");
    addUIString("swkbdProcessID", 0, "프로세스 ID 입력");
    addUIString("swkbdSysSavID", 0, "시스템 세이브 ID 입력");
    addUIString("swkbdRename", 0, "항목의 이름을 재설정");
    addUIString("swkbdMkDir", 0, "폴더 이름 작성");
    addUIString("swkbdNewSafeTitle", 0, "새 추출 폴더 작성");
    addUIString("swkbdExpandSize", 0, "새 MB 크기 설정");

    //Status informations
    addUIString("infoStatus", 0, "TID: %016lX");
    addUIString("infoStatus", 1, "SID: %016lX");
    addUIString("infoStatus", 2, "플레이 타임: %02d:%02d");
    addUIString("infoStatus", 3, "실행 횟수: %u");
    addUIString("infoStatus", 4, "제작사: %s");
    addUIString("infoStatus", 5, "저장 유형: %s");
    addUIString("infoStatus", 6, "캐시 인덱스: %u");
    addUIString("infoStatus", 7, "유저: %s");

    addUIString("debugStatus", 0, "유저수: ");
    addUIString("debugStatus", 1, "현재 유저: ");
    addUIString("debugStatus", 2, "실행 중 타이틀: ");
    addUIString("debugStatus", 3, "세이프 타이틀: ");
    addUIString("debugStatus", 4, "정렬 유형: ");

    addUIString("appletModeWarning", 0, "*경고*: 애플릿 모드로 실행 중이며 정상 작동하지 않을 수 있습니다.");
}

void ui::loadTrans()
{
    std::string transTestFile = fs::getWorkDir() + "trans.txt";
    std::string translationFile = "romfs:/lang/" + getFilename(data::sysLang);
    bool transFile = fs::fileExists(transTestFile);
    if(!transFile && (data::sysLang == SetLanguage_ENUS || data::sysLang == SetLanguage_ENGB || cfg::config["langOverride"]))
        ui::initStrings();
    else if(transFile)
        loadTranslationFile(transTestFile);
    else
        loadTranslationFile(translationFile);

    util::replaceButtonsInString(ui::strings[std::make_pair("helpUser", 0)]);
    util::replaceButtonsInString(ui::strings[std::make_pair("helpTitle", 0)]);
    util::replaceButtonsInString(ui::strings[std::make_pair("helpFolder", 0)]);
    util::replaceButtonsInString(ui::strings[std::make_pair("helpSettings", 0)]);
    util::replaceButtonsInString(ui::strings[std::make_pair("dialogYes", 0)]);
    util::replaceButtonsInString(ui::strings[std::make_pair("dialogNo", 0)]);
    util::replaceButtonsInString(ui::strings[std::make_pair("dialogOK", 0)]);
    util::replaceButtonsInString(ui::strings[std::make_pair("appletModeWarning", 0)]);
}

void ui::saveTranslationFiles(void *a)
{
    threadInfo *t = (threadInfo *)a;
    t->status->setStatus(ui::getUICString("infoStatus", 9));

    std::string outputFolder = fs::getWorkDir() + "lang", outputPath, romfsPath;
    fs::mkDir(outputFolder);

    //Save en-us first
    ui::initStrings();
    outputPath = fs::getWorkDir() + "lang/" + getFilename(SetLanguage_KO);
    FILE *out = fopen(outputPath.c_str(), "w");
    for(auto& s : ui::strings)
    {
        std::string stringOut = s.second;
            util::replaceStr(stringOut, "\n", "\\n");
            fprintf(out, "%s = %i, \"%s\"\n", s.first.first.c_str(), s.first.second, stringOut.c_str());
    }
    fclose(out);

    romfsInit();
    for(int i = 0; i < SetLanguage_Total; i++)
    {
        if(i == SetLanguage_KO)
            continue;

        outputPath = fs::getWorkDir() + "lang/" + getFilename(i);
        romfsPath = "romfs:/lang/" + getFilename(i);

        //Init original US English strings, then load translation over it. Result will be mixed file.
        ui::initStrings();
        loadTranslationFile(romfsPath);

        out = fopen(outputPath.c_str(), "w");
        for(auto& s : ui::strings)
        {
            std::string stringOut = s.second;
            util::replaceStr(stringOut, "\n", "\\n");
            fprintf(out, "%s = %i, \"%s\"\n", s.first.first.c_str(), s.first.second, stringOut.c_str());
        }
        fclose(out);
    }
    loadTrans();
    romfsExit();
    t->finished = true;
}
