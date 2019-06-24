#ifndef UREM_DMSprGrpTypDefectCFH                  
#define UREM_DMSprGrpTypDefectCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprGrpTypDefectCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprGrpTypDefectCF();                                                           
   ~TREM_DMSprGrpTypDefectCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
