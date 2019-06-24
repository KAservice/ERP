#ifndef UREM_DMSprModelTypRabotCFH                  
#define UREM_DMSprModelTypRabotCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprModelTypRabotCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprModelTypRabotCF();                                                           
   ~TREM_DMSprModelTypRabotCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
