#ifndef UFormaReportTouchForFRCFH                  
#define UFormaReportTouchForFRCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaReportTouchForFRCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaReportTouchForFRCF();                                                           
   ~TFormaReportTouchForFRCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
