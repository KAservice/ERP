#ifndef UREM_DMSprGrpNeisprCFH                  
#define UREM_DMSprGrpNeisprCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprGrpNeisprCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprGrpNeisprCF();                                                           
   ~TREM_DMSprGrpNeisprCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
