#ifndef UREM_FormaDocOtprPostCFH                  
#define UREM_FormaDocOtprPostCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaDocOtprPostCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaDocOtprPostCF();                                                           
   ~TREM_FormaDocOtprPostCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
