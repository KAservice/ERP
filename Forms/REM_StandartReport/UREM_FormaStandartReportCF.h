#ifndef UREM_FormaStandartReportCFH                  
#define UREM_FormaStandartReportCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaStandartReportCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaStandartReportCF();                                                           
   ~TREM_FormaStandartReportCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
