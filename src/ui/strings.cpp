#include <map>
#include <string>
#include "ui/strings.hpp"
#include "log.hpp"
#include "stringUtil.hpp"

namespace
{
    std::map<std::pair<std::string, int>, std::string> s_UIStringMap;
}

static void addUIString(const std::string &name, const int &index, const std::string &newString)
{
    s_UIStringMap[std::make_pair(name, index)] = newString;
}

static void replaceButtonsInString(std::string &str)
{
    stringUtil::replaceInString(str, "[A]", "\ue0e0");
    stringUtil::replaceInString(str, "[B]", "\ue0e1");
    stringUtil::replaceInString(str, "[X]", "\ue0e2");
    stringUtil::replaceInString(str, "[Y]", "\ue0e3");
    stringUtil::replaceInString(str, "[L]", "\ue0e4");
    stringUtil::replaceInString(str, "[R]", "\ue0e5");
    stringUtil::replaceInString(str, "[ZL]", "\ue0e6");
    stringUtil::replaceInString(str, "[ZR]", "\ue0e7");
    stringUtil::replaceInString(str, "[SL]", "\ue0e8");
    stringUtil::replaceInString(str, "[SR]", "\ue0e9");
    stringUtil::replaceInString(str, "[DPAD]", "\ue0ea");
    stringUtil::replaceInString(str, "[DUP]", "\ue0eb");
    stringUtil::replaceInString(str, "[DDOWN]", "\ue0ec");
    stringUtil::replaceInString(str, "[DLEFT]", "\ue0ed");
    stringUtil::replaceInString(str, "[DRIGHT]", "\ue0ee");
    stringUtil::replaceInString(str, "[+]", "\ue0ef");
    stringUtil::replaceInString(str, "[-]", "\ue0f0");
}

void ui::strings::init(void)
{
    // Init strings
    addUIString("author", 0, "NULL");
    addUIString("helpUser", 0, "[A] 선택   [Y] 모든 세이브 덤프   [X] 사용자 옵션");
    addUIString("helpTitle", 0, "[A] 선택   [L][R] 점프   [Y] 즐겨찾기   [X] 제목 옵션  [B] 뒤로가기");
    addUIString("helpFolder", 0, "[A] 선택  [Y] 복원  [X] 제거   [ZR] 업로드  [B] 닫기");
    addUIString("helpSettings", 0, "[A] 전환   [X] 기본   [B] 뒤로가기");

    // Y/N On/Off
    addUIString("dialogYes", 0, "예 [A]");
    addUIString("dialogNo", 0, "아니오 [B]");
    addUIString("dialogOK", 0, "확인 [A]");
    addUIString("settingsOn", 0, ">켬>");
    addUIString("settingsOff", 0, "끔");
    addUIString("holdingText", 0, "(홀드) ");
    addUIString("holdingText", 1, "(홀드 유지) ");
    addUIString("holdingText", 2, "(거의 완료!) ");

    // Confirmation Strings
    addUIString("confirmBlacklist", 0, "블랙리스트에 #%s# 을(를) 추가하겠습니까?");
    addUIString("confirmOverwrite", 0, "#%s#을(를) 덮어쓰시겠습니까?");
    addUIString("confirmRestore", 0, "#%s#을(를) 복원하겠습니까?");
    addUIString("confirmDelete", 0, "#%s#을(를) 영구적으로 제거하겠습니까?");
    addUIString("confirmCopy", 0, "#%s#을(를) #%s#에 복사하겠습니까?");
    addUIString("confirmDeleteSaveData", 0, "*주의*: 진행시 #%s#에 대한 세이브 데이터가 시스템에서 제거됩니다. 정말 하겠습니까?");
    addUIString("confirmResetSaveData", 0, "*주의*: 진행시 이 게임의 세이브 데이터가 *리셋됩니다*. 정말 하겠습니까?");
    addUIString("confirmCreateAllSaveData", 0, "이 시스템에서 #%s#에 대한 모든 세이브 데이터를 생성하겠습니까? 검색된 타이틀 수에 따라 시간이 걸릴 수 있습니다.");
    addUIString("confirmDeleteBackupsTitle", 0, "#%s#에 대한 모든 백업을 제거하겠습니까?");
    addUIString("confirmDeleteBackupsAll", 0, "모든 게임에 대한 세이브 백업을 제거하겠습니까?");
    addUIString("confirmDriveOverwrite", 0, "드라이브에서 이 백업을 다운로드하면 SD 카드에 있는 백업을 덮어씁니다. 계속합니까?");

    // Save Data related strings
    addUIString("saveDataNoneFound", 0, "#%s#의 세이브 데이터를 찾을 수 없습니다!");
    addUIString("saveDataCreatedForUser", 0, "%s의 세이브 데이터 저장!");
    addUIString("saveDataCreationFailed", 0, "세이브 데이터 생성 실패!");
    addUIString("saveDataResetSuccess", 0, "#%s# 재설정을 위해 저장합니다!");
    addUIString("saveDataDeleteSuccess", 0, "#%s#의 세이브 데이터가 제거되었습니다!");
    addUIString("saveDataExtendSuccess", 0, "#%s#의 세이브 데이터가 확장되었습니다!");
    addUIString("saveDataExtendFailed", 0, "세이브 데이터 확장에 실패했습니다.");
    addUIString("saveDataDeleteAllUser", 0, "*%s의 모든 세이브 데이터를 제거하겠습니까?*");
    addUIString("saveDataBackupDeleted", 0, "#%s#이(가) 제거되었습니다.");
    addUIString("saveDataBackupMovedToTrash", 0, "#%s#이(가) 휴지통으로 이동되었습니다.");
    addUIString("saveDataErrorMounting", 0, "세이브 데이터 마운트 중 오류 발생!");

    // This is redundant. Need to merge and use one or the other...
    addUIString("saveDataTypeText", 0, "시스템");
    addUIString("saveDataTypeText", 1, "어카운트");
    addUIString("saveDataTypeText", 2, "BCAT");
    addUIString("saveDataTypeText", 3, "기기");
    addUIString("saveDataTypeText", 4, "임시");
    addUIString("saveDataTypeText", 5, "캐시");
    addUIString("saveDataTypeText", 6, "시스템 BCAT");

    // Internet Related
    addUIString("onlineErrorConnecting", 0, "연결 오류!");
    addUIString("onlineNoUpdates", 0, "사용 가능한 업데이트가 없습니다.");

    // File mode menu strings
    addUIString("fileModeMenu", 0, "복사: ");
    addUIString("fileModeMenu", 1, "제거");
    addUIString("fileModeMenu", 2, "이름 변경");
    addUIString("fileModeMenu", 3, "폴더 생성");
    addUIString("fileModeMenu", 4, "속성");
    addUIString("fileModeMenu", 5, "닫기");
    addUIString("fileModeMenu", 6, "경로에 필터 추가");
    addUIString("fileModeMenuMkDir", 0, "새로 만들기");

    // New folder pop menu strings
    addUIString("folderMenuNew", 0, "새 백업");

    // File mode properties string
    addUIString("fileModeFileProperties", 0, "경로: %s\n크기: %s");
    addUIString("fileModeFolderProperties", 0, "경로: %s\n하위 폴더: %u\n파일 수: %u\n전체 크기: %s");

    // Settings menu
    addUIString("settingsMenu", 0, "휴지통 비우기");
    addUIString("settingsMenu", 1, "업데이트 확인");
    addUIString("settingsMenu", 2, "백업 경로 설정");
    addUIString("settingsMenu", 3, "블랙리스트 타이틀 설정");
    addUIString("settingsMenu", 4, "세이브 데이터 모두 제거");
    addUIString("settingsMenu", 5, "유저 및 세이브 데이터 포함: ");
    addUIString("settingsMenu", 6, "복원 시 자동 백업: ");
    addUIString("settingsMenu", 7, "백업 이름 자동 지정: ");
    addUIString("settingsMenu", 8, "오버클럭/CPU 부스트: ");
    addUIString("settingsMenu", 9, "길게 눌러 제거: ");
    addUIString("settingsMenu", 10, "길게 눌러 복원: ");
    addUIString("settingsMenu", 11, "길게 눌러 덮어쓰기: ");
    addUIString("settingsMenu", 12, "강제 마운트: ");
    addUIString("settingsMenu", 13, "어카운트 시스템 세이브: ");
    addUIString("settingsMenu", 14, "시스템 세이브 쓰기 활성화: ");
    addUIString("settingsMenu", 15, "FS 명령 직접 주입: ");
    addUIString("settingsMenu", 16, "ZIP 파일로 세이브 내보내기: ");
    addUIString("settingsMenu", 17, "영어 강제 사용: ");
    addUIString("settingsMenu", 18, "휴지통 활성화: ");
    addUIString("settingsMenu", 19, "정렬 유형: ");
    addUIString("settingsMenu", 20, "애니메이션 스케일: ");
    addUIString("settingsMenu", 21, "드라이브/Webdav로 자동 업로드: ");

    // Main menu
    addUIString("mainMenuSettings", 0, "설정");
    addUIString("mainMenuExtras", 0, "고급");

    // Translator in main page
    addUIString("translationMainPage", 0, "번역: ");

    // Loading page
    addUIString("loadingStartPage", 0, "로딩 중...");

    // Sort Strings for ^
    addUIString("sortType", 0, "알파벳순");
    addUIString("sortType", 1, "플레이 타임");
    addUIString("sortType", 2, "마지막 실행");

    // Extras
    addUIString("extrasMenu", 0, "SD 탐색기");
    addUIString("extrasMenu", 1, "BIS: ProdInfoF");
    addUIString("extrasMenu", 2, "BIS: Safe");
    addUIString("extrasMenu", 3, "BIS: System");
    addUIString("extrasMenu", 4, "BIS: User");
    addUIString("extrasMenu", 5, "보류 중인 업데이트 제거");
    addUIString("extrasMenu", 6, "프로세스 종료");
    addUIString("extrasMenu", 7, "시스템 세이브 마운트");
    addUIString("extrasMenu", 8, "타이틀 재검색");
    addUIString("extrasMenu", 9, "RomFS 프로세스 마운트");
    addUIString("extrasMenu", 10, "세이브 폴더 백업");
    addUIString("extrasMenu", 11, "*[개발자]* en-US 출력");

    // User Options
    addUIString("userOptions", 0, "%s 모두 덤프");
    addUIString("userOptions", 1, "세이브 데이터 생성");
    addUIString("userOptions", 2, "모든 세이브 데이터 생성");
    addUIString("userOptions", 3, "모든 유저 데이터 제거");

    // Title Options
    addUIString("titleOptions", 0, "상세 정보");
    addUIString("titleOptions", 1, "블랙리스트");
    addUIString("titleOptions", 2, "추출 폴더 변경");
    addUIString("titleOptions", 3, "파일 모드로 열기");
    addUIString("titleOptions", 4, "모든 세이브 백업 제거");
    addUIString("titleOptions", 5, "세이브 데이터 리셋");
    addUIString("titleOptions", 6, "세이브 데이터 제거");
    addUIString("titleOptions", 7, "세이브 데이터 확장");
    addUIString("titleOptions", 8, "SVI 내보내기");

    // Thread Status Strings
    addUIString("threadStatusCreatingSaveData", 0, "#%s#의 세이브 데이터 생성 중...");
    addUIString("threadStatusCopyingFile", 0, "'#%s#' 복사 중...");
    addUIString("threadStatusDeletingFile", 0, "제거 중...");
    addUIString("threadStatusOpeningFolder", 0, "'#%s#' 여는 중...");
    addUIString("threadStatusAddingFileToZip", 0, "'#%s#' ZIP 파일에 추가 중...");
    addUIString("threadStatusDecompressingFile", 0, "'#%s#' 압축 해제 중...");
    addUIString("threadStatusDeletingSaveData", 0, "#%s#의 세이브 데이터 제거 중...");
    addUIString("threadStatusExtendingSaveData", 0, "#%s#의 세이브 데이터 확장 중...");
    addUIString("threadStatusCreatingSaveData", 0, "#%s#의 세이브 데이터 생성 중...");
    addUIString("threadStatusResettingSaveData", 0, "세이브 데이터 리셋 중...");
    addUIString("threadStatusDeletingUpdate", 0, "대기 중인 업데이트 제거 중...");
    addUIString("threadStatusCheckingForUpdate", 0, "업데이트 확인 중...");
    addUIString("threadStatusDownloadingUpdate", 0, "업데이트 다운로드 중...");
    addUIString("threadStatusGetDirProps", 0, "폴더 속성 가져오는 중...");
    addUIString("threadStatusPackingJKSV", 0, "JKSV 폴더를 ZIP 파일에 쓰는 중...");
    addUIString("threadStatusSavingTranslations", 0, "마스터 파일 저장 중...");
    addUIString("threadStatusCalculatingSaveSize", 0, "세이브 데이터 크기 계산 중...");
    addUIString("threadStatusUploadingFile", 0, "#%s# 업로드 중...");
    addUIString("threadStatusDownloadingFile", 0, "#%s# 다운로드 중...");
    addUIString("threadStatusCompressingSaveForUpload", 0, "업로드를 위해 #%s# 압축 중...");

    // Random leftover pop-ups
    addUIString("popCPUBoostEnabled", 0, "ZIP을 위한 CPU 부스트가 활성화 됨.");
    addUIString("popErrorCommittingFile", 0, "세이브 커밋 중 오류 발생!");
    addUIString("popZipIsEmpty", 0, "ZIP 파일 비어있음!");
    addUIString("popFolderIsEmpty", 0, "폴더가 비어있음!");
    addUIString("popSaveIsEmpty", 0, "세이브 데이터가 비어있음!");
    addUIString("popProcessShutdown", 0, "'#%s#'이(가) 성공적으로 종료되었습니다.");
    addUIString("popAddedToPathFilter", 0, "'#%s#'이(가) 경로 필터에 추가되었습니다.");
    addUIString("popChangeOutputFolder", 0, "'#%s#'이(가) '#%s#'로 변경되었습니다.");
    addUIString("popChangeOutputError", 0, "'#%s#'에 잘못된 또는 ASCII가 아닌 문자가 포함되어 있습니다.'");
    addUIString("popTrashEmptied", 0, "휴지통을 비웠습니다.");
    addUIString("popSVIExported", 0, "SVI를 내보냈습니다.");
    addUIString("popDriveStarted", 0, "구글 드라이브가 성공적으로 시작되었습니다.");
    addUIString("popDriveFailed", 0, "구글 드라이브 시작에 실패했습니다.");
    addUIString("popDriveNotActive", 0, "구글 드라이브를 사용할 수 없습니다.");
    addUIString("popErrorMountingSave", 0, "세이브 데이터 마운트 오류!");

    // Keyboard hints
    addUIString("swkbdEnterName", 0, "새 이름 입력");
    addUIString("swkbdSaveIndex", 0, "캐시 인덱스 입력");
    addUIString("swkbdSetWorkDir", 0, "새 경로 입력");
    addUIString("swkbdProcessID", 0, "프로세스 ID 입력");
    addUIString("swkbdSysSavID", 0, "시스템 세이브 ID 입력");
    addUIString("swkbdRename", 0, "항목 이름 입력");
    addUIString("swkbdMkDir", 0, "폴더 이름 입력");
    addUIString("swkbdNewSafeTitle", 0, "새 출력 폴더 입력");
    addUIString("swkbdExpandSize", 0, "새 크기(MB) 입력");

    // Status informations
    addUIString("infoStatus", 0, "TID: %016lX");
    addUIString("infoStatus", 1, "SID: %016lX");
    addUIString("infoStatus", 2, "플레이 타임: %02d:%02d");
    addUIString("infoStatus", 3, "실행 횟수: %u");
    addUIString("infoStatus", 4, "개발사: %s");
    addUIString("infoStatus", 5, "세이브 유형: %s");
    addUIString("infoStatus", 6, "캐시 인덱스: %u");
    addUIString("infoStatus", 7, "유저: %s");

    addUIString("debugStatus", 0, "유저 수: ");
    addUIString("debugStatus", 1, "현재 유저: ");
    addUIString("debugStatus", 2, "현재 타이틀: ");
    addUIString("debugStatus", 3, "Safe 타이틀: ");
    addUIString("debugStatus", 4, "정렬 유형: ");

    addUIString("appletModeWarning", 0, "*주의*: 애플릿 모드로 실행 중, 많은 기능이 제한될 수 있습니다.");

    replaceButtonsInString(s_UIStringMap[std::make_pair("helpUser", 0)]);
    replaceButtonsInString(s_UIStringMap[std::make_pair("helpTitle", 0)]);
    replaceButtonsInString(s_UIStringMap[std::make_pair("helpFolder", 0)]);
    replaceButtonsInString(s_UIStringMap[std::make_pair("helpSettings", 0)]);
    replaceButtonsInString(s_UIStringMap[std::make_pair("dialogYes", 0)]);
    replaceButtonsInString(s_UIStringMap[std::make_pair("dialogNo", 0)]);
    replaceButtonsInString(s_UIStringMap[std::make_pair("dialogOK", 0)]);

    logger::log("ui::strings::init(): Succeeded.");
}

std::string ui::strings::getString(const std::string &name, int index)
{
    return s_UIStringMap[std::make_pair(name, index)];
}

const char *ui::strings::getCString(const std::string &name, int index)
{
    return s_UIStringMap[std::make_pair(name, index)].c_str();
}