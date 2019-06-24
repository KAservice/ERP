#ifndef UREM_DMSprModel2GrpCFH                  
#define UREM_DMSprModel2GrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprModel2GrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprModel2GrpCF();                                                           
   ~TREM_DMSprModel2GrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
