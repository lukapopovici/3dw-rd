#include <string>

class Pipeline{
   public:
      virtual void Init() = 0;
      virtual void OutPut_Debug()=0;
      virtual void Forward()=0;
      std::string outputFilePath;      
      bool debugEnabled;
};