#ifndef UREM_DMSprTrebRabotCFH                  
#define UREM_DMSprTrebRabotCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprTrebRabotCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprTrebRabotCF();                                                           
   ~TREM_DMSprTrebRabotCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
