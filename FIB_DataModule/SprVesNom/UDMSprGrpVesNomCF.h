#ifndef UDMSprGrpVesNomCFH                  
#define UDMSprGrpVesNomCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprGrpVesNomCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprGrpVesNomCF();                                                           
   ~TDMSprGrpVesNomCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
