#ifndef UREM_DMSprDefectModelNeisprCFH                  
#define UREM_DMSprDefectModelNeisprCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprDefectModelNeisprCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprDefectModelNeisprCF();                                                           
   ~TREM_DMSprDefectModelNeisprCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
