#ifndef UFormaReportKartKlientCFH                  
#define UFormaReportKartKlientCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaReportKartKlientCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaReportKartKlientCF();                                                           
   ~TFormaReportKartKlientCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
