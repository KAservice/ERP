#ifndef UFormaReportRashodProductCFH                  
#define UFormaReportRashodProductCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaReportRashodProductCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaReportRashodProductCF();                                                           
   ~TFormaReportRashodProductCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
