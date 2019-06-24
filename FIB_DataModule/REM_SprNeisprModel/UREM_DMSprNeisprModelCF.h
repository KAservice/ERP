#ifndef UREM_DMSprNeisprModelCFH                  
#define UREM_DMSprNeisprModelCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprNeisprModelCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprNeisprModelCF();                                                           
   ~TREM_DMSprNeisprModelCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
