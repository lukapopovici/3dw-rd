#include <string>

class Pipeline{
   public:
      virtual void Init() = 0;
      virtual void OutPut_Debug()=0;
      
   private:
      std::string OutputDir;      
      bool OutPut_Flag;
};