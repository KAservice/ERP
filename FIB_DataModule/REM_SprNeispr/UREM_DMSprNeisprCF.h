#ifndef UREM_DMSprNeisprCFH                  
#define UREM_DMSprNeisprCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprNeisprCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprNeisprCF();                                                           
   ~TREM_DMSprNeisprCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
