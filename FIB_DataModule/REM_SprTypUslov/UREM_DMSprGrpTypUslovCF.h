#ifndef UREM_DMSprGrpTypUslovCFH                  
#define UREM_DMSprGrpTypUslovCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprGrpTypUslovCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprGrpTypUslovCF();                                                           
   ~TREM_DMSprGrpTypUslovCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
