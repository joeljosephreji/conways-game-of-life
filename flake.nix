{
  description = "cpp flake starter for cpp projects";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
  };

  outputs =
    { self, nixpkgs, ... }@inputs:
    let
      system = "x86_64-linux";
      pkgs = nixpkgs.legacyPackages.${system};
    in
    {
      devShells.x86_64-linux = {
        default = pkgs.mkShell.override { stdenv = pkgs.clangStdenv; } {
          nativeBuildInputs = with pkgs; [
            # C++ Compiler is already part of stdenv
            gtest
            # boost
            cmake

            # dev tools
            clang-tools
          ];
        };
      };
    };
}
