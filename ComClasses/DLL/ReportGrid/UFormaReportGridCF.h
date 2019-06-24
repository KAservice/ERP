#ifndef UFormaReportGridCFH                  
#define UFormaReportGridCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaReportGridCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaReportGridCF();                                                           
   ~TFormaReportGridCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
