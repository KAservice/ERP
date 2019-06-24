#ifndef UDMSprNomFindCFH                  
#define UDMSprNomFindCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprNomFindCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprNomFindCF();                                                           
   ~TDMSprNomFindCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
