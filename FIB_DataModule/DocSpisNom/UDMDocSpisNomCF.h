#ifndef UDMDocSpisNomCFH                  
#define UDMDocSpisNomCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMDocSpisNomCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMDocSpisNomCF();                                                           
   ~TDMDocSpisNomCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
