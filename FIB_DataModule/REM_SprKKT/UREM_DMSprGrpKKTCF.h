#ifndef UREM_DMSprGrpKKTCFH                  
#define UREM_DMSprGrpKKTCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprGrpKKTCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprGrpKKTCF();                                                           
   ~TREM_DMSprGrpKKTCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
