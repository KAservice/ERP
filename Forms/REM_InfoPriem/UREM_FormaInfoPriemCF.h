#ifndef UREM_FormaInfoPriemCFH                  
#define UREM_FormaInfoPriemCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaInfoPriemCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaInfoPriemCF();                                                           
   ~TREM_FormaInfoPriemCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
