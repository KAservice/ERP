#ifndef UREM_DMSprTypRabotCFH                  
#define UREM_DMSprTypRabotCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprTypRabotCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprTypRabotCF();                                                           
   ~TREM_DMSprTypRabotCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
