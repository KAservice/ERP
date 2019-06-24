#ifndef UREM_DMSprKomplModelCFH                  
#define UREM_DMSprKomplModelCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprKomplModelCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprKomplModelCF();                                                           
   ~TREM_DMSprKomplModelCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
